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
int main(){
 	string c;
 	string c1;
 	cin>>c;
 	cin>>c1;
 	int fron[100005];
 	memset(fron,-1,sizeof(fron));
 	for(int i=0,j=0;i<c.length()&&j<c1.length();i++)
 	{
 		if(c[i]==c1[j]){
			fron[j]=i;
			j++;
		 }
	}
	int bak[100005];
	memset(bak,-1,sizeof(bak));
	int num=c1.length();
	for(int i=c.length()-1,j=c1.length()-1;i>=0&&j>=0;i--){
		if(c[i]==c1[j])
		{
			bak[j]=i;
			num=j;
			j--;
		}
	}
	int ma=c1.length()-num,f=0,b=num;
	for(int i=0,j=num;fron[i]!=-1;i++){
		//printf("%d ",i);
		while(j!=c1.length()&&((bak[j]<=fron[i]||bak[j]==-1)||j<=i))
		j++;
		if(j==c1.length()||i+1+c1.length()-j>ma)
		{
		//	printf("%d %d %d\n",j,fron[i],bak[j]);
			if(i+1+c1.length()-j>ma){
				ma=i+1+c1.length()-j;
				f=i+1,b=j;
			}
		}
	}
	if(ma==0)
	cout<<"-"<<endl;
	else
	cout<<c1.substr(0,f)<<c1.substr(b,c1.length()-b)<<endl;
}