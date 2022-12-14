#include<iostream>
#include<cstdio>
#define MN 2000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[MN+5],t[MN+5],S[MN+5];
int n,num[26],Ans[MN*3+5],ans;
void Work(int x)
{
//	cout<<"Work"<<x<<endl;
	for(int i=n-x+1;i<=n;++i) S[n+1-i]=s[i];
	for(int i=1;i<=n-x;++i) S[i+x]=s[i];
	for(int i=1;i<=n;++i) s[i]=S[i];
//	puts(s+1);
}
void Flip(int f,int s)
{
//	cout<<"Flip"<<f<<" "<<s<<endl;
	Ans[++ans]=n-s+1;Work(n-s+1);
	if(s-1-f) Ans[++ans]=s-1-f;Work(s-1-f);
	Ans[++ans]=f+1;Work(f+1);
} 
int main()
{
	n=read();scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i) ++num[s[i]-'a'],--num[t[i]-'a'];
	for(int i=0;i<26;++i) if(num[i]) return 0*puts("-1");
	for(int i=1,l=n/2+1,r=n/2;i<=n;++i)
	{
		int target=(i&1)?t[++r]:t[--l]; 
	//	cout<<"target="<<target-'a'<<endl;
		for(int j=i;j<=n;++j) if(s[j]==target){Flip(i-1,j);break;}
	//	puts(s+1);
	}
	if(~n&1) Ans[++ans]=n,Work(n);printf("%d\n",ans);
	for(int i=1;i<=ans;++i) printf("%d ",Ans[i]);
	return 0;
}