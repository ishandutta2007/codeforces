#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == y) printf("=");
    else if(x >= 3 and y >= 3)
        printf(x < y ? ">" : "<");
    else if(x >= 2 and y >= 2){
        if(x == 2){
            if(y == 3) printf("<");
            else if(y == 4) printf("=");
            else printf(">");
        }
        else{
            if(x == 3) printf(">");
            else if(x == 4) printf("=");
            else printf("<");
        }
    }
    else printf(x == 1 ? "<" : ">");
}