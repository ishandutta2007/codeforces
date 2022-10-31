#include<stdio.h>
char str[128];
int main(){
	scanf("%s",str);
	for(int i=0;str[i];i++){
		str[i]|=32;
		if(str[i]!='a'&&str[i]!='o'&&str[i]!='y'&&str[i]!='e'&&str[i]!='u'&&str[i]!='i')printf(".%c",str[i]);
	}
}