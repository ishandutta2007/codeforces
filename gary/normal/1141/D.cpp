#include<bits/stdc++.h>
using namespace std;
set<char> s;
map<char,queue<int> > m1;
map<char,queue<int> > m2;
int anstot=0;
vector<int> v1;
vector<int> v2;
bool OK=0;
int main(){
	int n; char tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>tmp;
		if(tmp=='?') OK=1;
		m1[tmp].push(i);
		s.insert(tmp);
	}
	for(int i=1;i<=n;i++){
		cin>>tmp;
		if(tmp=='?') OK=1;
		m2[tmp].push(i);
		s.insert(tmp);
	}
	set<char> ::iterator it = s.begin();
	if(OK) it++;
	for(it;it!=s.end();it++){
		while(m1[*it].size() &&m2[*it].size() ){
			anstot++;
			v1.push_back(m1[*it].front() );
			m1[*it].pop();
			v2.push_back(m2[*it].front() );
			m2[*it].pop();
		}
		if(m1[*it].size() ){
			while(m2['?'].size() &&m1[*it].size() ){
				anstot++;
				v1.push_back(m1[*it].front() );
				m1[*it].pop();
				v2.push_back(m2['?'].front() );
				m2['?'].pop();
			}
		}
		if(m2[*it].size() ){
			while(m1['?'].size() &&m2[*it].size() ){
				anstot++;
				v1.push_back(m1['?'].front() );
				m1['?'].pop();
				v2.push_back(m2[*it].front() );
				m2[*it].pop();
			}
		}
	}
	if(OK){
		it=s.begin();
		while(m1[*it].size() &&m2[*it].size() ){
			anstot++;
			v1.push_back(m1[*it].front() );
			m1[*it].pop();
			v2.push_back(m2[*it].front() );
			m2[*it].pop();
		}
	}
	printf("%d\n",anstot);
	for(int i=0;i<anstot;i++){
		printf("%d %d\n",v1[i],v2[i]);
	}
	return 0;
}