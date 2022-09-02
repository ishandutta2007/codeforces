#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int num[100005];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    string str;
    int to=0;
    for(int j=n-1;j>=0;j--){
        if(to-num[j]<=num[j] && to-num[j]>=-num[j]){
            str.push_back('-'); to-=num[j];
        }else{
            str.push_back('+'); to+=num[j];
        }
    }
    reverse(str.begin(),str.end());
    if(to<0){
        for(int i=0;i<str.size();i++){
            if(str[i]=='+'){
                str[i]='-';
            }else{
                str[i]='+';
            }
        }
    }
    printf("%s%c",str.c_str(),10);
}