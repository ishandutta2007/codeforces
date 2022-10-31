#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[1048576];
int ans[1000000];
int main(){
    scanf("%s",str);
    int len=strlen(str);
    int left=0;
    int right=len-1;
    for(int i=0;i<len;i++){
        if(str[i]=='r'){
            ans[left++]=i;
        }else ans[right--]=i;
    }
    for(int i=0;i<len;i++)printf("%d\n",ans[i]+1);
}