#include<cstdio>
#include<bits/stdc++.h>
#include<cstring>
#include<algorithm>
#define rep(a,b,c) for (int a=b;a<=c;a++)
using namespace std;
char s1[300010],s2[300010],s3[300010];
int main(){
	scanf("%s%s",s1,s2);
	int n=strlen(s1);
	sort(s1,s1+n);
	sort(s2,s2+n,greater<char>());
	int nw=0,tl=n,h1=0,t1,h2=0,t2;
	while (s1[h1]<s2[h2]&&nw<n){
		s3[nw++]=s1[h1++];
		if (s1[h1]>=s2[h2]) break;
		s3[nw++]=s2[h2++];
	}
	if (nw&1)
	t1=h1+(n-nw)/2,
	t2=h2+(n-nw+1)/2; else
	t1=h1+(n-nw+1)/2,
	t2=h2+(n-nw)/2;
	if (nw&1&&tl>nw) s3[--tl]=s2[--t2];
	while (tl>nw){
		s3[--tl]=s1[--t1];
		if (tl>nw) s3[--tl]=s2[--t2];
	}
	rep(i,0,n-1) putchar(s3[i]);
	return 0;
}