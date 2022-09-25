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

int n,k;
vector<int> rocks;
vector<int> idk;
vector<int> gifts;

string res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	rep(tc,1,TC+1){
		rocks.clear();
		idk.clear();
		gifts.clear();
		
		cin>>n>>k;
		
		int curr=1;
		
		rep(x,0,25){
			int testing;
			do{
				testing=rng.next()%n+1;
			}while (testing==curr);
			
			cout<<"? 1 1"<<endl;
			cout<<curr<<endl;
			cout<<testing<<endl;
			
			cin>>res;
			if (res=="SECOND") curr=testing;
		}
		
		rep(x,n+1,1){
			if (x==curr) rocks.push_back(x);
			else idk.push_back(x);
		}
		
		while (gifts.empty()){
			int num=min(sz(rocks),sz(idk));
			
			cout<<"? "<<num<<" "<<num<<endl;
			rep(x,0,num) cout<<rocks[x]<<" ";
			cout<<endl;
			rep(x,sz(idk)-num,sz(idk)) cout<<idk[x]<<" ";
			cout<<endl;
			
			cin>>res;
			if (res=="EQUAL"){
				rep(x,0,num){
					rocks.push_back(idk.back());
					idk.pop_back();
				}
			}
			else{
				rep(x,0,num){
					gifts.push_back(idk.back());
					idk.pop_back();
				}
			}
		}
		
		//for (auto &it:gifts) cout<<it<<endl;
		
		reverse(all(gifts));
		
		while (sz(gifts)!=1){
			int num=sz(gifts)/2;
			
			cout<<"? "<<num<<" "<<num<<endl;
			rep(x,0,num) cout<<rocks[x]<<" ";
			cout<<endl;
			rep(x,sz(gifts)-num,sz(gifts)) cout<<gifts[x]<<" ";
			cout<<endl;
			
			cin>>res;
			if (res=="EQUAL"){
				rep(x,0,num){
					gifts.pop_back();
				}
			}
			else{
				while (sz(gifts)!=num){
					gifts.erase(gifts.begin());
				}
			}
		}
		
		cout<<"! "<<gifts[0]<<endl;
	}
}