#include <bits/stdc++.h>

using namespace std;

char s[100005];
int change[100005];

int main(){
	scanf("%s", s);
	int num=0;
	int ansN=0;
	int numLast=0;
	int posLast;
	for(int i=0; s[i]; ++i){
		if(s[i] == '('){
			++num;
			change[i]=1;
		}
		else{
			change[i]=-1;
			--num;
			if(num < 0){
				puts("-1");
				return 0;
			}
			if(s[i] == '#'){
				posLast=i;
				++ansN;
				numLast=num;
			}
		}
	}
	change[posLast]=-num-1;
	num=0;
	for(int i=0; s[i]; ++i){
		num += change[i];
		if(num < 0){
			puts("-1");
			return 0;
		}
	}
	for(int i=0; i < ansN-1; ++i)
		printf("1\n");
	printf("%d\n", -change[posLast]);
}