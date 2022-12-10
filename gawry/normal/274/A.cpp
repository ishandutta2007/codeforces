#include<cstdio>
#include<set>
using namespace std;
set<int> t;
main(){
	int n,k;
				scanf("%d %d",&n,&k);
				while(n--){
				int x;
				scanf("%d",&x);
				t.insert(x);
				}
				int ans=0;
				while(!t.empty()){
								int cur=*t.rbegin(),len=0;
								while(t.find(cur)!=t.end()){
												++len;
												t.erase(cur);
												if(cur%k)break;
												cur/=k;
								}
								ans+=(len+1)/2;

				}
				printf("%d\n",ans);
}