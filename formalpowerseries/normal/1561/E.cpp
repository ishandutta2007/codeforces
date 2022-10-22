#include<bits/stdc++.h>
using namespace std;
int n,a[2025];
int find(int x,int up)
{
	for(int i=1;i<=up;++i)	if(a[i]==x)	return i;
	return -1;
}
void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)	if((i&1)^(a[i]&1))	{puts("-1");return ;}
	vector<int> Ans;
	for(int i=n;i>=3;i-=2)
	{
		int pos=find(i,i);
		assert(pos!=-1);
		Ans.push_back(pos);
		reverse(a+1,a+1+pos);
		pos=find(i-1,i);
		Ans.push_back(pos-1); //It's impossible to make pos-1=0
		reverse(a+1,a+pos);
		Ans.push_back(pos+1);
		reverse(a+1,a+pos+2);
		Ans.push_back(3);
		swap(a[1],a[3]);
		Ans.push_back(i);
		reverse(a+1,a+1+i);
	}
	printf("%d\n",int(Ans.size()));
	for(auto st:Ans)	printf("%d ",st);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}