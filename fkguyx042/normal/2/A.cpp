#include <iostream>
#include <map>
#include <set>
#include <string>

#define N 1000

using namespace std;

int n,Max,score[N+10];
string name[N+10];
set<string> Set;
map<string,int> sum;

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>name[i]>>score[i];
		sum[name[i]]+=score[i];
	}
	for (map<string,int>::iterator i=sum.begin();i!=sum.end();++i)
		if (i->second>Max) Max=i->second;
	for (map<string,int>::iterator i=sum.begin();i!=sum.end();++i)
		if (i->second==Max) Set.insert(i->first);
	sum.clear();
	for (int i=1;i<=n;++i)
		if (Set.count(name[i])){
			sum[name[i]]+=score[i];
			if (sum[name[i]]>=Max){
				cout<<name[i]<<endl;
				return 0;
			}
		}
}