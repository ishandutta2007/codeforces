#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define pb push_back
#define ll long long
using namespace std;

const int INF=1000111222,st=100005;
int n,t[st],RES;
struct cmp
{
	bool operator()(int a, int b)
	{
		return t[a]<t[b];
	}
};
set<int,cmp> S;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]);
	t[0]=INF;
	S.insert(0);
	for(int i=1;i<=n;++i){
		while(t[*S.begin()]<t[i]){
			RES=max(RES,t[*S.begin()]^t[i]);
			S.erase(S.begin());
		}
		S.insert(i);
	}
	S.clear();
	S.insert(0);
	for(int i=n;i>=1;--i){
		while(t[*S.begin()]<t[i]){
			RES=max(RES,t[*S.begin()]^t[i]);
			S.erase(S.begin());
		}
		S.insert(i);
	}
	printf("%d",RES);
	return 0;
}