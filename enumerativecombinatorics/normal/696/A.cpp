#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
map<long long,long long> m;
long long u[110];
long long v[110];
int main(){
	int a;scanf("%d",&a);
	while(a--){
		int t;scanf("%d",&t);
		if(t==1){
			long long p,q,r;scanf("%I64d%I64d%I64d",&p,&q,&r);
			int sa=0;
			int sb=0;
			while(p){
				u[sa++]=p;
				p/=2;
			}
			while(q){
				v[sb++]=q;
				q/=2;
			}
			int sl=0;
			for(int i=0;i<min(sa,sb);i++){
				if(u[sa-1-i]==v[sb-1-i])sl++;
				else break;
			}
			for(int i=0;i<sa-sl;i++){
				m[u[i]]+=r;
			}
			for(int i=0;i<sb-sl;i++){
				m[v[i]]+=r;
			}
		}else{
			long long p,q;scanf("%I64d%I64d",&p,&q);
			int sa=0;
			int sb=0;
			while(p){
				u[sa++]=p;
				p/=2;
			}
			while(q){
				v[sb++]=q;
				q/=2;
			}
			int sl=0;
			long long ret=0;
			for(int i=0;i<min(sa,sb);i++){
				if(u[sa-1-i]==v[sb-1-i])sl++;
				else break;
			}
			for(int i=0;i<sa-sl;i++){
				if(m.count(u[i]))ret+=m[u[i]];
			}
			for(int i=0;i<sb-sl;i++){
				if(m.count(v[i]))ret+=m[v[i]];
			}
			printf("%I64d\n",ret);
		}
	}
}