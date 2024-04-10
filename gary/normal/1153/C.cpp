/*
	*#*#*#* Author GaryMr *#*#*#*
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int len;
string s;
int main(){
	scanf("%d",&len);
	if(len%2){
		printf(":(\n");
		return 0;
	}
	cin>>s;
//	len=s.length();
	if(s[0]==')'||s[len-1]=='('){
		printf(":(\n");
		return 0;
	}
	s[0]='(';s[len-1]=')';
	int chazhi=0;// 
	queue<int> q;
	for(int i=1;i<len-1;i++){
		if(s[i]=='('){
			chazhi++;
		}
		if(s[i]==')'){
			chazhi--;
		}
		if(s[i]=='?'){
			s[i]=')';
//			cout<<i<<endl;
			q.push(i);
			chazhi--;
		}
		if(chazhi<0){
			if(q.empty()){
				printf(":(\n");
				return 0;
			}
			else{
				s[q.front()]='(';
				q.pop();
				chazhi+=2;
			}
		}
	}
	if(chazhi){
		printf(":(\n");
		return 0;
	}
	cout<<s<<endl;
	return 0;
}