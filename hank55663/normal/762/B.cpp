#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define Max(a,b,c) max(a,max(b,c))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
#define pmm pair<map<int,int>*,map<int,LL>*>
typedef long long LL;
using namespace std;
const LL mod=1e9+7;
bool isprime[40000000];
vector<LL> USB;
vector<LL> PS;
int main(){
 	int a,b,c;
 	scanf("%d %d %d",&a,&b,&c);
 	int m;
 	scanf("%d",&m);
 	for(int i=0;i<m;i++){
 		LL p;
 		char c[10];
 		scanf("%I64d %s",&p,c);
 		if(c[0]=='U')
 		USB.pb(p);
 		else
 		PS.pb(p);
	 }
	 sort(USB.begin(),USB.end());
	 sort(PS.begin(),PS.end());
	 vector<LL>::iterator it=USB.begin();
	 vector<LL>::iterator it2=PS.begin();
	 LL ans=0;
	 int num=0;
	 for(int i=0;it!=USB.end()&&i<a;it++,i++)
	 ans+=*it,num++;
	 for(int i=0;it2!=PS.end()&&i<b;it2++,i++)
	 ans+=*it2,num++;
	 for(int i=0;(it!=USB.end()||it2!=PS.end())&&i<c;i++){
	 	if(it!=USB.end()){
	 		if(it2!=PS.end()){
	 			if(*it<*it2)
	 			ans+=*it,it++,num++;
	 			else 
	 			ans+=*it2,it2++,num++;
			}
			else if(it2==PS.end()){
				ans+=*it,it++,num++;
			}
		}
		else if(it2!=PS.end()){
			ans+=*it2;
			it2++;
			num++;
		}
	}
	printf("%d %I64d\n",num,ans);
}