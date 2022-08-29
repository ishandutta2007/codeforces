#include<cstdio>
#include<vector>
#define pi pair<int,int>
#define mp make_pair
#define re register
using namespace std;
vector<pi >v[200002];
int n,a[100002],sq[100002];
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int main(){
	n=read();
	for(re int i=1;i<=100000;++i)
		for(re int j=i+1;1ll*j*j-1ll*i*i<=200000;++j)
			v[1ll*j*j-1ll*i*i].push_back(mp(i,j));
	for(re int i=2,x;i<=n;i+=2){
		x=read();
		for(re int j=0;j<v[x].size();++j)
			if(v[x][j].first>sq[i-2]){
				sq[i-1]=v[x][j].first;
				sq[i]=v[x][j].second;
				break;
			}
		if(!sq[i])return puts("No"),0;
	}
	puts("Yes");
	for(re int i=1;i<=n;++i)printf("%lld ",1ll*sq[i]*sq[i]-1ll*sq[i-1]*sq[i-1]);
}