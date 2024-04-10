#include <stdio.h>

using namespace std;

int operationN, number;
char text[1100005], newText[1100005];

int main()
{
	int best=1000000, print=-1, printj;
	scanf("%d%d", &operationN, &number);
	if(number == 1){
		if(operationN == 1)
			printf("0\nT");
		else
			printf("IMPOSSIBLE");
		return 0;
	}
	if(number == 2){
		if(operationN == 2)
			printf("0\nTB");
		else
			printf("IMPOSSIBLE");
		return 0;
	}
	for(int i=1; i < number; ++i){
		for(int j=0; j < 2; ++j){
			int a=number, b=i, mistakes=0, ops=0;
			bool top=0, newTop;
			if(j == 1){
				a=i;
				b=number;
				top=1;
			}
			while(true){
				if(a > b){
					++ops;
					a=a-b;
					newTop=1;
				}
				else{
					++ops;
					b=b-a;
					newTop=0;
				}
				if(newTop == top)
					++mistakes;
				top=newTop;
				if(a < 1 || b < 2)
					break;
				if(a == 1 && b == 2)
					break;
			}
			if(top == 0)
				++mistakes;
			if(a == 1 && b == 2){
				if(ops+2 == operationN && mistakes < best){
					best=mistakes;
					print=i;
					printj=j;
				}
			}
		}
	}
	if(print == -1){
		printf("IMPOSSIBLE");
	}
	else{
		printf("%d\n", best);
		int i=print;
		int j=printj;
		int a=number, b=i, textL=0;
		if(j == 1){
			a=i;
			b=number;
		}
		while(true){
			if(a > b){
				a=a-b;
				text[textL++]='T';
			}
			else{
				b=b-a;
				text[textL++]='B';
			}
			if(a == 1 && b == 1)
				break;
		}
		text[textL++]='T';
		text[textL]=0;
		for(int k=textL-1; k >= 0; --k)
			newText[k]=text[textL-k-1];
		printf("%s", newText);
	}
	return 0;
}