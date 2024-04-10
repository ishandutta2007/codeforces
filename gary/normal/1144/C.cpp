#include<bits/stdc++.h>
using namespace std;
int n;
int a;
map<int,int> m;
set<int> s1;
set<int> s2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(m[a]>=2){
			printf("NO\n");
			return 0;
		}
		if(m[a]==0){
			m[a]++;
			s1.insert(a);
		}
		else{
			m[a]++;
			s2.insert(a);
		}
	}
	printf("YES\n");
	int len=s1.size();
	printf("%d\n",len);
	set<int> ::iterator ite;
	ite=s1.begin();
	for(ite;ite!=s1.end();ite++){
		printf("%d ",*ite);
	}
	printf("\n");
	len=s2.size();
	ite=s2.begin();
	printf("%d\n",len);
	stack<int> ans;
	for(ite;ite!=s2.end();ite++){
		ans.push(*ite);
//		cout<<*ite<<endl;
	}
	for(int i=1;i<=len;i++){
		printf("%d ",ans.top() );
		ans.pop();
	}
	return 0;
}