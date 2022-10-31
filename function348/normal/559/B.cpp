#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200010;
char s[N],t[N];
int cnt[40];
int check(int l1,int r1,int l2,int r2)
{
	if ((r1-l1+1)%2==1)
	{
		for (int i=l1;i<=r1;i++)
		if (s[i]!=t[i-l1+l2]) return 0;
		return 1;
	}
	int f=1;
	for (int i=l1;i<=r1;i++)
	if (s[i]!=t[i-l1+l2]) f=0;
	if (f) return 1;
	for (int i=0;i<26;i++) cnt[i]=0;
	for (int i=l1;i<=r1;i++) cnt[s[i]-'a']++;
	for (int i=l2;i<=r2;i++) cnt[t[i]-'a']--;
	for (int i=0;i<26;i++) if (cnt[i]!=0) return 0;
	int p1=(l1+r1)/2,p2=(l2+r2)/2;
	if (check(l1,p1,l2  ,p2)&&check(p1+1,r1,p2+1,r2)) return 1;
	if (check(l1,p1,p2+1,r2)&&check(p1+1,r1,l2  ,p2)) return 1;
	return 0;
}
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	int n=strlen(s+1);
	printf(check(1,n,1,n)?"YES\n":"NO\n");
	return 0;
}