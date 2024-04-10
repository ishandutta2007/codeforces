//A.cpp
#include<cstdio>
#include<cstring>

char S[11],s1[11],s2[11];

int main(){
	int N,n1=0,n2=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s",S);

		if(!strlen(s1))
			memcpy(s1,S,(strlen(S)+1)*sizeof(S[0]));
		else if(strcmp(s1,S)&&!strlen(s2))
			memcpy(s2,S,(strlen(S)+1)*sizeof(S[0]));
		if(strcmp(S,s1)==0)
			n1++;
		else
			n2++;
	}
   	printf("%s\n",n1>n2?s1:s2);

	return 0;
}