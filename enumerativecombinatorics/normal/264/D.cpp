#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
char S[1048576];
char T[1048576];
int L[1048576];
int R[1048576];
vector<int> v[3][3];
char str[]="RGB";
int main(){
    scanf("%s%s",S,T);
    int at=0;
    for(int i=0;i<1048576;i++)L[i]=R[i]=-1;
    for(int i=1;T[i];i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(str[j]==T[i-1]&&str[k]==T[i]){
                    v[j][k].push_back(i);
                }
            }
        }
    }
    L[0]=0;
    for(int i=0;S[i];i++){
        L[i]=at;
        if(S[i]==T[at])at++;
      //  if(T[at]==0)break;
    }
    at=0;
    for(int i=0;T[i];i++){
        R[at]=i;
        if(T[i]==S[at])at++;
      //  if(S[at]==0)break;
    }
    for(int i=1;S[i];i++)R[i]=max(R[i],R[i-1]);
    long long ret=0LL;
    for(int i=0;S[i];i++){
        if(!~L[i])break;
        ret+=R[i]-L[i]+1;
    }
    //for(int i=0;S[i];i++)printf("%d %d\n",L[i],R[i]);
    for(int i=1;S[i];i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k)continue;
                if(str[j]==S[i-1]&&str[k]==S[i]){
                    ret-=(upper_bound(v[k][j].begin(),v[k][j].end(),R[i])-lower_bound(v[k][j].begin(),v[k][j].end(),L[i]));
                }
            }
        }
    }
    printf("%I64d\n",ret);
}