#include<stdio.h>
#include<algorithm>
using namespace std;
int table[26];
char str[131072];
pair<int,int> S[26];
bool del[26];
int main(){
    int a;
    scanf("%s%d",str,&a);
    int n;
    for(n=0;str[n];n++)table[str[n]-'a']++;
    if(n<=a){
        printf("0\n\n");
        return 0;
    }
    for(int i=0;i<26;i++)S[i]=make_pair(table[i],i);
    std::sort(S,S+26);
    int ret=26;
    for(int i=0;i<26;i++){
        if(S[i].first<=a){
            del[S[i].second]=true;
            ret--;
            a-=S[i].first;
        }
    }
    printf("%d\n",ret);
    for(int i=0;str[i];i++)if(!del[str[i]-'a'])printf("%c",str[i]);
    printf("\n");
}