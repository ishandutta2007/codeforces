#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

struct RNG{
    typedef unsigned long long ull;
    ///taken from http://prng.di.unimi.it/xoshiro256plusplus.c
    ull s[4];

    RNG(ull a, ull b, ull c, ull d){
        ///please seed this with something legit
        s[0]=a,s[1]=b,s[2]=c,s[3]=d;

        for (int x=0;x<1024;x++) next(); //give some random
    }

    static inline ull rotl(const ull x, int k){
        return (x << k) | (x >> (64 - k));
    }


    ull next() {
        const ull result = rotl(s[0] + s[3], 23) + s[0];

        const ull t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);

        return result;
    }
}rng=RNG(423358081,274988025,50131061,866741066);


int n;
ll arr[200005];
vector<ll> potential;

vector<int> primes;
void generateprime(int i){
    bool arr[i];
    int sqrti=sqrt(i);
    memset(arr,true,sizeof(arr));
    for (int x=2;x<=i;x++){
        if (arr[x]){
            primes.push_back(x);
            if (x<=sqrti) for (int y=x*x;y<=i;y+=x){
                arr[y]=false;
            }
        }
    }
}


void fac(ll i){
	if (i<=1) return;
	
	for (auto &it:primes){
		if (i%it==0){
			potential.push_back(it);
			do{
				i/=it;
			}while (i%it==0);
			
			if (i==1) return;
		}
	}
	
	potential.push_back(i);
}

ll test(ll i){
	ll res=0;
	
	rep(x,0,n){
		ll temp=arr[x]/i*i;
		if (temp) res+=min(arr[x]-temp,temp+i-arr[x]);
		else res+=temp+i-arr[x];
	}
	
	//cout<<i<<" "<<res<<endl;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	generateprime(1000005);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,20){
		int index=rng.next()%n;
		fac(arr[index]-1);
		fac(arr[index]);
		fac(arr[index]+1);
	}
	
	ll ans=n;
	
	for (auto &it:potential){
		ans=min(ans,test(it));
	}
	
	cout<<ans<<endl;
}