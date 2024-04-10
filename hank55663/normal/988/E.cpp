#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define last Last
using namespace std;
typedef long long LL;
int num(char *temp,char a,char b){
	int sum=0,f=0,s=0;
	for(int i=0;temp[i]!=0;i++){
		if(temp[i]==b){
			f=1;
			for(int j=i-1;j>=0;j--)
			swap(temp[j],temp[j+1]),sum++;
			break;
		}
	}
	if(f)
	for(int i=1;temp[i]!=0;i++){
		if(temp[i]==a){
			s=1;
			for(int j=i-1;j>0;j--){
				sum++;
				swap(temp[j],temp[j+1]);
			}
			break;
		}
	}
	for(int i=strlen(temp)-1;i>=0;i--){
		if(temp[i]=='0')
		sum++;
		else
		break;
	}
	if(f&&s)
	return sum;
	return 1e9;
}
int main(){
	char c[20];
	scanf("%s",c);
	reverse(c,c+strlen(c));
	char temp[20];
	for(int i=0;c[i]!=0;i++)
	temp[i]=c[i],temp[i+1]=0;
	int ans=1e9;
	ans=min(num(temp,'0','0'),ans);
	//printf("%d\n",ans);
	for(int i=0;c[i]!=0;i++)
	temp[i]=c[i];
	ans=min(num(temp,'2','5'),ans);
	//printf("%d\n",ans);
	for(int i=0;c[i]!=0;i++)
	temp[i]=c[i];
	ans=min(num(temp,'5','0'),ans);
	//printf("%d\n",ans);
	for(int i=0;c[i]!=0;i++)
	temp[i]=c[i];
	ans=min(num(temp,'7','5'),ans);
	//printf("%d\n",ans);
	for(int i=0;c[i]!=0;i++)
	temp[i]=c[i];
	if(ans==1e9)
	printf("-1\n");
	else
	printf("%d\n",ans);
}