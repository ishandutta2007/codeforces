#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,m;
char arr[55][55];
vector<ii> v,v2;
int d;
char s[55];
void print(){
    for (int x=1;x<=n;x++){
        for (int y=1;y<=m;y++){
            printf("%c",arr[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}
void flip(int x,int y){
    if (arr[x][y]=='L'){
        if (arr[x+1][y]=='U') flip(x+1,y);
        arr[x][y]='U';
        arr[x+1][y]='D';
        arr[x][y+1]='U';
        arr[x+1][y+1]='D';
        v.push_back(ii(x,y));
    }
    else{
        if (arr[x][y+1]=='L') flip(x,y+1);
        arr[x][y]='L';
        arr[x+1][y]='L';
        arr[x][y+1]='R';
        arr[x+1][y+1]='R';
        v.push_back(ii(x,y));
    }
    //print();
}
void kill(){
    printf("-1\n");
    exit(0);
}
void check(){
    for (int x=1;x<=n;x++){
        for (int y=1;y<=m;y++){
            if (arr[x][y]=='U'){
                if (arr[x+1][y]!='D') kill();
            }
            else if (arr[x][y]=='L'){
                if (arr[x][y+1]!='R') kill();
            }
            else if (arr[x][y]=='D'){
                if (arr[x-1][y]!='U') kill();
            }
            else{
                if (arr[x][y-1]!='L') kill();
            }
        }
    }
}
void stuff(){
    for (int x=1;x<=n;x++){
        fgets(s,55,stdin);
        for (int y=1;y<=m;y++){
            arr[x][y]=s[y-1];
        }
    }
    check();
    for (int x=1;x<=n;x++){
        for (int y=1;y<=m;y++){
            if (d==0 && arr[x][y]=='L'){
                flip(x,y);
            }
            else if (d==1 && arr[x][y]=='U'){
                flip(x,y);
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    char c=getchar();
    while (c!='\n') c=getchar();
    if ((n&1)==0) d=0;
    else if ((m&1)==0) d=1;
    else kill();
    stuff();
    swap(v,v2);
    stuff();
    reverse(v.begin(),v.end());
    printf("%d\n",v2.size()+v.size());
    for (int x=0;x<v2.size();x++){
        printf("%d %d\n",v2[x].first,v2[x].second);
    }
    for (int x=0;x<v.size();x++){
        printf("%d %d\n",v[x].first,v[x].second);
    }
}