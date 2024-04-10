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
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char c[200005];
		char ans[200005];
		scanf("%s",c);
		int len=strlen(c);
		int allz=(c[0]=='1');
		for(int i=1;c[i]!=0;i++)
		if(c[i]!='0'&&(c[i+1]!=0||c[i]!='1'))
		allz=0;
		if(len%2==1||allz){
			for(int j=0;j<len-2+len%2;j++)
			printf("9");
			printf("\n");
			continue;
		}
		int cnt[10];
		MEM(cnt);
		for(int i=0;c[i]!=0;i++){
			cnt[c[i]-'0']^=1;
			ans[i]=c[i];
		}
		ans[len]=0;
		for(int i=strlen(c)-1;i>=0;i--){
			cnt[c[i]-'0']^=1;
			vector<int> v;
			int tot=0;
			for(int j=0;j<10;j++)
			if(cnt[j])
			tot++;
			if(tot>len-i)
			continue;
			int temp[10];
			for(int j=0;j<10;j++)
			temp[j]=cnt[j];
			//printf("%d\n",tot);
			if(tot<=len-i){
				int fi=0;
				for(int k=c[i]-'0'-1;k>=0;k--){
					if(tot!=len-i||cnt[k]==1){
						ans[i]=k+'0';
						fi=1;
						tot-=cnt[k];
						cnt[k]^=1;
						tot+=cnt[k];
						break;
					}
				}
				//printf("%d %c %d\n",i,ans[i],tot);
			//	printf("%d %d\n",i,fi);
				if(!fi)
				continue;
				for(int j=i+1;j<len;j++){
					if(tot!=len-j){
						//printf("%d %d ",j,tot);
						ans[j]='9';
						tot-=cnt[9];
						cnt[9]^=1;
						tot+=cnt[9];
					}
					else{
						for(int k=9;k>=0;k--){
							if(cnt[k]){
								//printf("? %d",k);
								ans[j]=k+'0';
								cnt[k]=0;
								tot--;
								break;
							}
						}
					}
				//	printf("%d %c %d\n",j,ans[j],tot);
				}
				break;
			}
		}
		printf("%s\n",ans);
	}
}