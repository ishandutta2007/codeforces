#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define pb push_back

const int st=1000123;
set<int> s;
int res[st];
set<int>::iterator it,it2;


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)s.insert(i);s.insert(1e9);
	while(m--){
		int a,b,x;
		scanf("%d%d%d",&a,&b,&x);
		it=s.lower_bound(a);
		while(*it<=b){
			if((*it)!=x){
				res[*it]=x;
				it2=it;
				it++;
				s.erase(it2);
			}
			else it++;
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",res[i]);
	return 0;
}