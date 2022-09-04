#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int mod=1e8+7;
int main() {
	char c[100005];
	while(scanf("%s",c+1)!=EOF){ 
	char ans[100005];
	MEM(ans);
	for(int i=1;c[i]!=0;i++){
		if(c[i]>'7'){
			//printf("%s\n",ans+1);
			for(int j=i-1;j>=0;j--){
				if(ans[j]=='4'){
					ans[j]='7';
					break;
				}
				else{
					ans[j]='4';
				}
			}//printf("%s\n",ans+1);
			for(int j=i;c[j]!=0;j++)
			ans[j]='4';
			break;
		}
		else if(c[i]>'4'){
			ans[i]='7';
			if(c[i]!='7'){
				for(int j=i+1;c[j]!=0;j++)
				ans[j]='4';
				break;
			}
		}
		else{
			ans[i]='4';
			if(c[i]!='4'){
					for(int j=i+1;c[j]!=0;j++)
				ans[j]='4';
				break;
			}
		}
	}
//	printf("%s\n",ans+1);
	int f=0,s=0;
	for(int i=0;ans[i]!=0||i==0;i++)
	{
		if(ans[i]=='4')
		f++;
		else if(ans[i]=='7')
		s++;
	}
	if((f+s)%2!=0){
		int num=(f+s)/2+1;
		for(int i=0;i<num;i++)
		printf("4");
		for(int i=0;i<num;i++)
		printf("7");
		continue;
	}
	else if(f<s){
		int num=(f+s)/2+1;
		int ok=0;
		for(int i=strlen(ans+1);i>=0;i--){
			if(ans[i]=='7'){
				f++;
				s--;
			}
			else if(ans[i]=='4'&&f-s>=2){
				ans[i]='7';
				f--;
				s++;
				for(int j=i+1;ans[j]!=0;j++)
				ans[j]='4';
				for(int j=strlen(ans+1);f!=s;j--){
					ans[j]='7';
					f--;
					s++;
				}
				ok=1;
				break;
			}
		//	printf("%d %d\n",f,s);
		}
		if(!ok){
			for(int i=0;i<num;i++)
			printf("4");
			for(int i=0;i<num;i++)
			printf("7");
			continue;
		}
	}
	{
	//	printf("%d %d\n",f,s);
		for(int i=strlen(ans+1);f>s;i--)
		if(ans[i]=='4'){
			ans[i]='7';
			f--;
			s++;
		}
		
		if(ans[0])
		printf("%s",ans);
		else
		printf("%s",ans+1);
	}
	} 
}