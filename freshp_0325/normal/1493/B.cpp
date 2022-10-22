#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int h,m;
pair<int,int> Next(int H,int M)
{
	++M;
	if(M==m)	M=0,++H;
	if(H==h)	H=0;
	return mp(H,M);
}
bool avail[15]={true,true,true,false,false,true,false,false,true,false};
int rever[15]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool check(int H,int M)
{
	if(!avail[H%10] || !avail[H/10] || !avail[M%10] || !avail[M/10])	return false;
	H=rever[H%10]*10+rever[H/10],M=rever[M%10]*10+rever[M/10];
	swap(H,M);
	if(H<h && M<m)
	return true;
	return false;
}
void write(int x)
{
	if(x<10)	putchar('0');
	printf("%d",x);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d %d",&h,&m);
		int s,t;
		scanf("%d:%d",&s,&t);
		while(!check(s,t))
		{
			pair<int,int> a=Next(s,t);
			s=a.first,t=a.second;
		}
		write(s),putchar(':'),write(t),puts("");
	}
	return 0;
}