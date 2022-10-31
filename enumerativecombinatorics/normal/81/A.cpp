#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
char t[524288];
char res[524288];
int main(){
    scanf("%s",t);
    int len=strlen(t);
    stack<char> S;
    S.push(t[0]);
    for(int i=1;i<len;i++){
        if(!S.empty()&&S.top()==t[i])S.pop();
        else S.push(t[i]);
    }
    len=S.size();
    res[len]=0;
    for(int i=len-1;i>=0;i--){
        res[i]=S.top();
        S.pop();
    }
    printf("%s\n",res);
}