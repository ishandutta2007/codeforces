#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=400010,p=1000000007;
int a[N],b[N],c[N];
int pa,pb,pc,d;
int n,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char s[4];int x;
		scanf("%s %d",s,&x);
		if (s[0]==49&&s[1]==49) d++,ans+=x;else
		if (s[0]==48&&s[1]==48) a[++pa]=x;else
		if (s[0]==48&&s[1]==49) b[++pb]=x;else
			c[++pc]=x;
	}
	sort(a+1,a+1+pa,greater<int>());
	sort(b+1,b+1+pb,greater<int>());
	sort(c+1,c+1+pc,greater<int>());
	for (int i=1;i<=min(pb,pc);i++) ans+=b[i]+c[i];
	if (pb<pc)
		{
			for (int i=pb+1;i<=pc;i++) b[i]=c[i];
			swap(pb,pc);
		}
	int tmp=0;
	pa=min(pa,d);
	for (int i=1;i<=pa;i++) tmp+=a[i];
	int t=0;
	for (int i=pa,j=pc;i>=0;i--)
	{
		while (d-i>=j-pc+1&&j<=pb) j++,tmp+=b[j];
		t=max(t,tmp);
		tmp-=a[i];
	}
	cout<<t+ans;
	return 0;
}