#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005

using namespace std;
int i,j,m,n,p,k,a,b,c,d,e,f;
int sqr(int x) { return x*x; }
int main()
{
	 scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	 printf("%d\n",(int)sqr(a+b+c)-sqr(a)-sqr(c)-sqr(e));
}