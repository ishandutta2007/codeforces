#include <stdio.h>
#include <algorithm>

using namespace std;

char text[100015];

bool check(int c1, int c2){
    if(text[c1] == '(' && text[c2] == ')')
        return 1;
    if(text[c1] == '[' && text[c2] == ']')
        return 1;
    return 0;
}

int ans=-1, ansS, ansE;

pair<int, int> rec(int pos){
    int sum=0;
    bool first=0;
    if(pos == 0)
        first=1;
    for(int p=pos; true; ++p){
        if(text[p] == '(' || text[p] == '['){
            pair<int, int> r=rec(p+1);
            if(r.second == -1){
                if(first){
                    sum=0;
                    p=r.first;
                    pos=p+1;
                }
                else
                    return r;
            }
            if(check(p, r.first)){
                sum += r.second+(text[p]=='['?1:0);
                if(sum > ans){
                    ans=sum;
                    ansS=pos;
                    ansE=r.first+1;
                }
                p=r.first;
            }
            else{
                if(first && text[r.first]){
                    sum=0;
                    p=r.first;
                    pos=p+1;
                }
                else
                    return make_pair(r.first, -1);
            }
        }
        else{
            if(first){
                sum=0;
                pos=p+1;
                if(!text[p])
                    return make_pair(0, -1);
            }
            else
                return make_pair(p, sum);
        }
    }
}

int main()
{
    scanf("%s", text);
    rec(0);
    if(ans == -1)
        printf("0");
    else{
        text[ansE]=0;
        printf("%d\n%s", ans, text+ansS);
    }
    return 0;
}