#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[128];
int bit[262144];
int has[26];
int First[26];
int End[26];
bool t[26][200003];
int Count[26];
char out[400000];
char in[2];
void add(int a,int b){
    for(;a<262144;a|=a+1)bit[a]+=b;
}
int sum(int a,int b){
    if(a)return sum(0,b)-sum(0,a-1);
    int ret=0;
    for(;b>=0;b=(b&(b+1))-1)ret+=bit[b];
    return ret;
}
int main(){
    int a;
    scanf("%d%s",&a,str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        has[str[i]-'a']++;
    }
    int now=0;
    for(int i=0;i<26;i++){
        First[i]=now;
        now+=has[i]*a;
        End[i]=now;
    }
    //printf("%d\n",now);
    for(int i=0;i<26;i++){
        for(int j=First[i];j<End[i];j++){
            add(j,1);
        }
    }
    int b;
    scanf("%d",&b);
    for(int i=0;i<b;i++){
        int c;
        scanf("%d%s",&c,in);
        int d=in[0]-'a';
        int left=-1;
        int right=has[d]*a+1;
        while(left+1<right){
            int M=(left+right)/2;
            if(c<=sum(First[d],First[d]+M)){
                right=M;
            }else left=M;
        }
        t[d][right]=true;
    //  printf("%d\n",query(First[d]+c-1));
    //  printf("%d\n",right);
        add(First[d]+right,-1);
    }
    int at=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<len;j++){
            if(!t[str[j]-'a'][Count[str[j]-'a']])out[at++]=str[j];
            Count[str[j]-'a']++;
        }
    }
    printf("%s\n",out);
}