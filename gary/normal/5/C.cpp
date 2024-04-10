#include<bits/stdc++.h>
using namespace std;
struct Gary{
	char brackets;
	int number;
};
string line;
long long len;
stack<Gary> check_stack;
bool str[1000001]={0};
int main(){
	map<long long,long long> anstot;
	long long MAX_ans=0,temp_MAX=0;
	char tempchar;
	tempchar=getchar();
	while(tempchar!='\n'){
		line+=tempchar;
		tempchar=getchar();
	}
	len=line.length();
	for(long long i=0;i<len;i++){
		Gary temp_check;
		temp_check.number =i;
		temp_check.brackets =line[i];
		if(temp_check.brackets =='('){
			check_stack.push(temp_check);
		}
		if(temp_check.brackets ==')'&&!check_stack.empty()){
			Gary to_p=check_stack.top();
			if(to_p.brackets=='('){
				str[temp_check.number ]=1;
				str[to_p.number ]=1;
				check_stack.pop();
			}
		}
	}
	for(int i=0;i<len;i++){
		if(str[i]){
			temp_MAX++; 	
		}
		if(!str[i]||i==len-1){
			MAX_ans=max(MAX_ans,temp_MAX);
			anstot[temp_MAX]++;
			temp_MAX=0;
		}
	}
	anstot[0]=1;
	printf("%lld %lld\n",MAX_ans,anstot[MAX_ans]);
	return 0;
}