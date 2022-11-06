#include<bits/stdc++.h>
#define ll long long
#define maxi 7000
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
bitset<maxi+10> an[100010],yin[maxi+10],be[maxi+10];
int n,q,miu[maxi+10],opt,x,y,z;
int que(int x){for (int i=2;i*i<=x;i++)if (x%(i*i)==0)return 0;return 1;}
int main(){
	read(n);read(q);
	for (int i=1;i<=maxi;i++)
		for (int j=i;j<=maxi;j+=i)yin[j][i]=1;
	for (int i=maxi;i>=1;i--)miu[i]=que(i);
	for (int i=1;i<=maxi;i++)
		for (int j=i;j<=maxi;j+=i)be[i][j]=miu[j/i];
	while (q--){
		read(opt);read(x);read(y);
		if (opt==1)an[x]=yin[y];
		if (opt==2){read(z);an[x]=an[y]^an[z];}
		if (opt==3){read(z);an[x]=an[y]&an[z];}
		if (opt==4)printf("%d",(an[x]&be[y]).count()%2);
	}
	puts("");
	return 0;
}