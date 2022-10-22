#include <stdio.h>
#include <string.h>

using namespace std;

int colonyN, type[1000005], nextPara[3000005], para[3000005];
char input[3000005], tmpInput[1000005];

int rec(int start){
	int depth=0;
	int type=0, Type[2], tested=0, oper;
	//0=Says nothing
	//1=0/1
	//2=Done!
	//3=0
	//4=1
	if(input[start] == '?' && input[start+1] == ')')
		return 1;
	if(input[start] == '0' && input[start+1] == ')')
		return 3;
	if(input[start] == '1' && input[start+1] == ')')
		return 4;
	Type[0]=rec(start+1);
	Type[1]=rec(nextPara[start]+3);
	if(input[nextPara[start]+1] == '&')
		oper=2;
	if(input[nextPara[start]+1] == '|')
		oper=1;
	if(input[nextPara[start]+1] == '^')
		oper=0;
	if((Type[0] == 3 || Type[1] == 3) && oper == 2)
		return 3;
	if((Type[0] == 4 || Type[1] == 4) && oper == 1)
		return 4;
	if(Type[0]+Type[1] == 7){
		if(oper == 2)
			return 3;
		return 4;
	}
	if(Type[0] == 4 && Type[1] == 4){
		if(oper == 0)
			return 3;
		return 4;
	}
	if(Type[0] == 3 && Type[1] == 3){
		return 3;
	}
	if(Type[0] == 2 || Type[1] == 2)
		return 2;
	if(Type[0] >= 3)
		return Type[1];
	if(Type[1] >= 3)
		return Type[0];
	if(oper && (Type[0] == 1 || Type[1] == 1))
		return 2;
	if(oper)
		return 0;
	if(Type[0] == Type[1])
		return 0;
	return 1;
}

int main()
{
	scanf("%d", &colonyN);
	scanf("%s", tmpInput);
	if(!tmpInput[0]){
		printf("NO");
		return 0;
	}
	int L=0;
	for(int i=0; tmpInput[i]; ++i){
		if(tmpInput[i] == '?'){
			input[L++]='(';
			input[L++]='?';
			input[L++]=')';
		}
		else if(tmpInput[i] == '0'){
			input[L++]='(';
			input[L++]='0';
			input[L++]=')';
		}
		else if(tmpInput[i] == '1'){
			input[L++]='(';
			input[L++]='1';
			input[L++]=')';
		}
		else{
			input[L++]=tmpInput[i];
		}
	}
	int paraN=0;
	for(int i=0; input[i]; ++i){
		if(input[i] == '('){
			para[paraN++]=i;
		}
		else if(input[i] == ')'){
			nextPara[para[--paraN]]=i;
		}
	}
	int ans;
	if(input[0] == '(')
		ans=rec(1);
	else{
		int i;
		for(i=0; input[i]; ++i);
		input[i]=')';
		input[i+1]=0;
		ans=rec(0);
	}
	if(ans == 1 || ans == 2)
		printf("YES");
	else
		printf("NO");
	return 0;
}