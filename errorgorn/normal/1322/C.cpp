#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>

struct RNG{
    typedef unsigned long long ull;
    ///taken from http://prng.di.unimi.it/xoshiro256plusplus.c
    ull s[4];

    RNG(ull a, ull b, ull c, ull d){
        ///please seed this with something legit
        s[0]=a,s[1]=b,s[2]=c,s[3]=d;
		for (int x=0;x<1024;x++) next();
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
};

const ll MOD[]={1000000007,1000000009};

int n,m;
ll h[500005];
ll val[500005][2];
map<ii,int> um;
bool used[500005];


ll arr[500005];
int p[500005];
int r[500005];


struct ufds{
    void init(){
        for (int x=1;x<=n;x++){
            p[x]=x;
            r[x]=0;
        }
    }
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) return;
        if (r[i]<r[j]){
            p[i]=j;
			arr[j]+=arr[i];
        }
        else{
            p[j]=i;
			arr[i]+=arr[j];
            if (r[i]==r[j]) r[i]++;
        }
    }
}dsu=ufds();

int main(){
	srand(time(0));
	RNG rng=RNG(rand(),rand(),rand(),rand());
	
	for (int x=0;x<500005;x++) h[x]=rng.next()&((1<<30)-1);
	
	int TC;
	cin>>TC;
	while (TC--){
		scanf("%d%d",&n,&m);
		for (int x=1;x<=n;x++){
			used[x]=false;
			val[x][0]=val[x][1]=0;
		}
		um.clear();
		dsu.init();
		for (int x=1;x<=n;x++) scanf("%lld",&arr[x]);
		
		int a,b;
		while (m--){
			scanf("%d%d",&a,&b);
			used[b]=true;
			for (int x=0;x<2;x++) 
				val[b][x]=(val[b][x]+h[a])%MOD[x];
				
		}
		
		for (int x=1;x<=n;x++){
			if (um.count(ii(val[x][0],val[x][1]))){
				dsu.unions(um[ii(val[x][0],val[x][1])],x);
			}
			else{
				um[ii(val[x][0],val[x][1])]=x;
			}
		}
		
		ll ans=0;
		for (int x=1;x<=n;x++){
			if (used[x]){
				ans=__gcd(ans,arr[dsu.parent(x)]);
				//cout<<dsu.parent(x)<<" "<<arr[dsu.parent(x)]<<endl;
			}
		}
		
		printf("%lld\n",ans);
	}
}