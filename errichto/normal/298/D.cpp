#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;
int n,m,k,a,suma;
map<int,int> mapa;
set<int> s;
vector<int> w;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	while(n--){
		scanf("%d",&a);
		mapa[a]++;
		s.insert(a);
	}
	while(m--){
		scanf("%d",&a);
		mapa[a]--;
		s.insert(a);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();++it)
		w.push_back(*it);
	reverse(w.begin(),w.end());
	for(int i=0;i<w.size();++i){
		suma+=mapa[w[i]];
		if(suma>0) return !printf("YES");
	}
	printf("NO");
	return 0;
}