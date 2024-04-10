#include <stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
struct team{char s[31];int p,a,b;};
team v[51];
char s1[31],s2[31],c,l1,l2,sc[31];
bool cmp1(team a,team b){
    if(a.p>b.p)
        return true;
    else
        if(a.p<b.p)
            return false;
        else
            if(a.a-a.b>b.a-b.b)
                return true;
            else
                if(a.a-a.b<b.a-b.b)
                    return false;
                else
                    if(a.a>b.a)
                        return true;
                    else
                        return false;
}
bool cmp2(team a,team b){
    if(strcmp(a.s,b.s)<0)
        return true;
    else
        return false;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,nr1,nr2,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%s",&v[i].s);
    for(i=1;i<=n*(n-1)/2;i++){
        l1=-1;
        l2=-1;
        scanf("\n");
        scanf("%c",&c);
        while(c!='-'){
            l1++;
            s1[l1]=c;
            scanf("%c",&c);
        }
        s1[l1+1]=NULL;
        scanf("%c",&c);
        while(c!=' '){
            l2++;
            s2[l2]=c;
            scanf("%c",&c);
        }
        s2[l2+1]=NULL;
        nr1=0;
        nr2=0;
        scanf("%s",&sc);
        k=0;
        while(sc[k]>='0'&&sc[k]<='9'){
            nr1=nr1*10+sc[k]-'0';
            k++;
        }
        k++;
        while(sc[k]>='0'&&sc[k]<='9'){
            nr2=nr2*10+sc[k]-'0';
            k++;
        }
        k=1;
        while(strcmp(s1,v[k].s)!=0)
            k++;
        v[k].a+=nr1;
        v[k].b+=nr2;
        if(nr1>nr2)
            v[k].p+=3;
        if(nr1==nr2)
            v[k].p++;
        k=1;
        while(strcmp(s2,v[k].s)!=0)
            k++;
        v[k].a+=nr2;
        v[k].b+=nr1;
        if(nr2>nr1)
            v[k].p+=3;
        if(nr2==nr1)
            v[k].p++;
    }
    sort(v+1,v+n+1,cmp1);
    sort(v+1,v+n/2+1,cmp2);
    for(i=1;i<=n/2;i++){
        nr1=strlen(v[i].s);
        for(k=0;k<=nr1-1;k++)
            printf("%c",v[i].s[k]);
        printf("\n");
    }
    return 0;
}