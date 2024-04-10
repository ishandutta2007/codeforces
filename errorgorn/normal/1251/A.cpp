#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool exist[30];
bool ok[30];
int main(){
    int TC;
    scanf("%d",&TC);
    string s;
    int num;
    char prev;
    while (TC--){
        memset(exist,false,sizeof(exist));
        memset(ok,false,sizeof(ok));
        cin>>s;
        prev=0;
        num=0;
        for (int x=0;x<s.size();x++){
            exist[s[x]-'a']=true;
            if (s[x]!=prev) {
                if (num%2==1){
                    ok[prev-'a']=true;
                }
                num=1;
                prev=s[x];
            }
            else{
                num++;
            }
        }
        if (num%2==1){
            ok[prev-'a']=true;
        }
        for (int x=0;x<26;x++){
            if (exist[x]&&ok[x]) printf("%c",x+'a');
        }
        printf("\n");
    }

}