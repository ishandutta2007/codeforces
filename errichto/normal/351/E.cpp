#include<cstdio>
#include<algorithm>
using namespace std;
const int st=100005;
int n;
int t[st];
int zle,ZLE;
int RES;
bool jest[st];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&t[i]);
		if(t[i]<0)t[i]=-t[i];
		jest[t[i]]=1;
	}
	for(int z=100000;z>0;--z)if(jest[z]){
		ZLE=0;
		zle=0;
		for(int i=0;i<n;++i)
			if(t[i]<z)ZLE++;
		for(int i=0;i<n;++i){
			if(t[i]==z) RES+=min(zle,ZLE-zle);
			if(t[i]<z) zle++;
		}
	}
	printf("%d",RES);
	return 0;
}