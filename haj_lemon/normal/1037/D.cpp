#include<bits/stdc++.h>
using namespace std;
struct Info{int nu,ne;}a[400010];
struct pp{int x,y;}c[200010];
int b[200010],x,y,t[200010],f[200010],n,num,li[200010];
bool ans=true,vi[200010];
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;}
bool comp(const pp &a,const pp &b){if (a.y!=b.y)return a.y>b.y; return a.x>b.x;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){scanf("%d %d",&c[i].x,&c[i].y);}
	for (int i=1;i<=n;i++){scanf("%d",&t[i]);f[t[i]]=i;}
	if (t[1]!=1){cout<<"No"<<endl;return 0;}
	for (int i=1;i<n;i++){c[i].x=f[c[i].x];c[i].y=f[c[i].y];if (c[i].x>c[i].y)swap(c[i].x,c[i].y);}
	sort(c+1,c+n,comp);
	for (int i=1;i<n;i++){jb(c[i].x,c[i].y);}
	int l=1,r=1;li[l]=1;vi[1]=false;
	for (int i=2;i<=n;i++) vi[i]=true;
	while (l<=r){
		for (int y=b[li[l]];y;y=a[y].ne){
			if (vi[a[y].nu]){
				vi[a[y].nu]=false;
				li[++r]=a[y].nu;
			}
		}
		l++;
	}
	for (int i=1;i<=n;i++) if (li[i]!=i) ans=false;
	if (ans) cout<<"Yes"<<endl;else cout<<"No"<<endl;
	return 0;
}