#include<bits/stdc++.h>
using namespace std;
#define N 500050
const int inf=0x3f3f3f3f;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
char s[N];
int maxX,minX,maxY,minY,maxZ,minZ;
struct Point{
	int x,y;
}a[N];
void init(){
	minX=minY=0;
	maxX=maxY=maxZ=inf;
	minZ=-inf;
}
bool check(int k){
	init();
	for(int i=1;i<=n;++i){
		minX=max(minX,a[i].x-k);
		maxX=min(maxX,a[i].x+k);
		minY=max(minY,a[i].y-k);
		maxY=min(maxY,a[i].y+k);
		minZ=max(minZ,a[i].x-a[i].y-k);
		maxZ=min(maxZ,a[i].x-a[i].y+k);
	}
	int l=minX-maxY,r=maxX-minY;
	if(l>r||l>maxZ||r<minZ||minX>maxX||minY>maxY||minZ>maxZ)return false;
	return true;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int j=1;j<=len;++j){
			if(s[j]=='B')++a[i].x;
			else ++a[i].y;
		}
	}
	int l=0,r=1e6+233,ans=inf;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	check(ans);
	printf("%d\n",ans);
	int X=min(maxX,maxY+maxZ);
	int Y=min(X-minZ,maxY);
	while(X--)putchar('B');
	while(Y--)putchar('N'); 
	return 0;
}