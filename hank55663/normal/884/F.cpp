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
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int a[200005];
int main(){
	int n;
	scanf("%d",&n);
	char c[105];
	scanf("%s",c);
	int b[105];
	int sub=0;
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		sum+=b[i];
	}
	int cnt[30];
	MEM(cnt);
	int tot=0;
	for(int i=0;i<n/2;i++){
		if(c[i]==c[n-i-1]){
			sub+=min(b[i],b[n-i-1]);
			cnt[c[i]-'a']++;
			tot++;
		}
	}
	//printf("%d\n",tot);
	for(int i=0;i<26;i++){
	//	printf("%d ",cnt[i]);
		if(cnt[i]>tot/2){
	//		printf("%d",i);
			vector<int> v;
			for(int j=0;j<n/2;j++){
				if(c[j]!=c[n-j-1]){
					if(c[j]==i+'a'){
					}
					else if(c[n-j-1]==i+'a'){
					}
					else{
						v.pb(min(b[n-j-1],b[j]));
				//		printf("%d ",v.back());
					}
				}
			}
			sort(v.begin(),v.end());
			for(int j=0;j<v.size();j++){
			//	printf("%d %d",v[j],tot);
				tot++;
				sub+=v[j];
				if(cnt[i]<=tot/2)
				break;
			}
		}
	}
	printf("%d\n",sum-sub);
	return 0;
}