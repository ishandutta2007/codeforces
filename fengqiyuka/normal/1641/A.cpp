#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

const int N=2e5+100,lim=1e9;
int a[N];
multiset<int> B;
multiset<int>::iterator iter;

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n,X;
		scanf("%d%d",&n,&X);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		B.clear();
		for(int i=1;i<=n;i++) B.insert(a[i]);
		
		int Ans=0;
		while(!B.empty()){
			iter=B.begin();
			int t=(*iter);B.erase(iter);
			if(lim/t>=X){
				iter=B.find(t*X);
				if(iter!=B.end()&&(*iter)==t*X) B.erase(iter);
				else Ans++;
			}
			else Ans++;
		}
		
		printf("%d\n",Ans);
	}
	
	return 0;
}