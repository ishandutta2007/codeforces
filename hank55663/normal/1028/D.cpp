#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int mod=1e9+7;
int main(){
	int q;
	int Min=0,Max=1e9;
	scanf("%d",&q);
	set<int> s;
	LL ans=1;
	while(q--){
		string st;
		int x;
		cin>>st>>x;
		if(st=="ADD"){
			s.insert(x);
		}
		else{
			if(s.find(x)==s.end()){
				printf("0\n");
				return 0;
			}
			else{
				if(x>Min&&x<Max){
					ans*=2;
					ans%=mod;
					auto it=s.find(x);
					if(it!=s.begin()){
						it--;
						Min=*it;
						it++;
					}
					else{
						Min=0;
					}
					it++;
					if(it!=s.end()){
						Max=*it;
					}
					else{
						Max=1e9;
					}
				}
				else if(x==Min){
					auto it=s.find(x);
					if(it!=s.begin()){
						it--;
						Min=*it;
						it++;
					}
					else{
						Min=0;
					}
					it++;
					if(it!=s.end()){
						Max=*it;
					}
					else{
						Max=1e9;
					}
				}
				else if(x==Max){
					auto it=s.find(x);
					if(it!=s.begin()){
						it--;
						Min=*it;
						it++;
					}
					else{
						Min=0;
					}
					it++;
					if(it!=s.end()){
						Max=*it;
					}
					else{
						Max=1e9;
					}
				}
				else{
					printf("0\n");
					return 0;
				}
				s.erase(x);
			}
		}
	}
	int cnt=1;
	for(auto it:s){
		if(it>Min&&it<Max){
			cnt++;
		}
	}
	ans=ans*cnt%mod;
	printf("%lld\n",ans);
}