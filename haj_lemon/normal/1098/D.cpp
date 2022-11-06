#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
multiset<int> g[34];
int q,ma[34],si[34],mi[34],nu,x;
ll su[34];
void rc(int x){si[x]=g[x].size();if (si[x])mi[x]=(*g[x].begin());}
void add(int x){
	nu++;
	for (int i=0,l=1,r=1;;i++,l=l*2,r=r*2+1)if (x>=l&&x<=r){g[i].insert(x);rc(i);su[i]+=x;return ;}
}
void dec(int x){
	nu--;
	for (int i=0,l=1,r=1;;i++,l=l*2,r=r*2+1)if (x>=l&&x<=r){g[i].erase(g[i].find(x));rc(i);su[i]-=x;return ;}
}
int que(){
	if (!nu)return 0;
	int s2=0,an=nu-1;ll s1=0;
	for (int i=0,j=0;;i++,j++){
		while (!si[i])i++;
		s2+=si[i];s1+=su[i];
		if (s2==nu)return an;
		j=i+1;while (!si[j])j++;
		if (s1*2<mi[j])an--;
	}
}
int main(){
	read(q);
	for (int i=1;i<=q;i++){
		char ch=getchar();while (ch!='+'&&ch!='-')ch=getchar();read(x);
		if (ch=='+')add(x);else dec(x);
		printf("%d\n",que());
	}
	return 0;
}