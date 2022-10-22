#include<bits/stdc++.h>
using namespace std;
int n,s[200005],A,B,a,b;
int Abs(int x){return x>0?x:-x;}
bool check(int x)
{
	int dist=max(Abs(A-a),Abs(B-b));
	if(x<dist)	return false;
	if(x>dist+min(a,b)*2)	return false;
	return (x-dist)%2==0;
}
void Solve()
{
	scanf("%d %d",&a,&b);
	n=a+b;
	vector<int> Ans;
	A=n/2,B=n-A;
	for(int i=0;i<=n;++i)	if(check(i))	Ans.push_back(i);
	swap(A,B);
	for(int i=0;i<=n;++i)	if(check(i))	Ans.push_back(i);
	sort(Ans.begin(),Ans.end());
	Ans.erase(unique(Ans.begin(),Ans.end()),Ans.end());
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