#include<bits/stdc++.h>
using namespace std;
const int N=2000000+5;
const int inf=2147483647;

int _, cnt, len[N*2], pos2, ans;
char t[N], ss[N*2];
int p[N*2];

string manacher(string str){
    int n=(int)str.size();
    for(int i=0;i<(n<<1)-1;i++) len[i]=0;
    len[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;++i){
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1&&q+len[i]<n&&str[p-len[i]]==str[q+len[i]]) ++len[i];
        if(q+len[i]-1>r) j=i;
    }
    int LL=-1,RR=-1;
    for (int i=0;i<n;i++){
        int L=i-len[i*2]+1,R=i+len[i*2]-1;
        if (L<=R&&(L==0||R==n-1)){
            if (LL==-1||R-L>RR-LL) LL=L,RR=R;
        }
    }
    for (int i=0;i<n-1;i++){
        int L=i+1-len[i*2+1],R=i+len[i*2+1];
        if (L<=R&&(L==0||R==n-1)){
            if (LL==-1||R-L>RR-LL) LL=L,RR=R;
        }
    }
    if (LL==-1) return "";
    string ret="";
    for (int i=LL;i<=RR;i++) ret+=str[i];
    return ret;
}


int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%s",t);
        int n=strlen(t),pp=0;
        while (pp<(n-1)/2&&t[pp]==t[n-pp-1]) ++pp;
        string s="";
        for (int i=pp;i<n-pp;i++) s+=t[i];
        //manacher(s);
        //printf("%d\n",ans);
        string S="";
        for (int i=0;i<pp;i++) S+=t[i];
        S+=manacher(s);
        for (int i=0;i<pp;i++) S+=t[n-pp+i];
        cout << S << endl;
        //assert(S.size()<=n);
    }
    return 0;
}