#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char arr[10];
int main(){
    //freopen("input.txt","r",stdin);
    memset(arr,'0',sizeof(arr));
    int n;
    scanf("%d",&n);
    getchar();
    char ch;
    while (n--){
        ch=getchar();
        if (ch=='L'){
            for (int x=0;x<10;x++){
                if (arr[x]=='0'){
                    arr[x]='1';
                    break;
                }
            }
        }
        else if (ch=='R'){
            for (int x=9;x>=0;x--){
                if (arr[x]=='0'){
                    arr[x]='1';
                    break;
                }
            }
        }
        else{
            arr[ch-'0']='0';
        }
    }
    cout<<arr;
}