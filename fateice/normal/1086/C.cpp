#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int t,n,m;
char a[1000010],b[1000010],s[1000010],x[300],u[300];
bool y[300],v[300],p;
inline bool chka(int i)
{
    int j;
    for(j='a';j<='z';j++)
      u[j]=x[j],v[j]=y[j];
    u[s[i]]=a[i];
    v[a[i]]=1;
    for(i++;i<n;i++)
      if(u[s[i]])
        if(u[s[i]]<a[i])
          return 0;
        else if(u[s[i]]>a[i])
          return 1;
        else
          {}
      else
        {
         for(j=a[i]+1;j<=m;j++)
           if(!v[j])
             {
              u[s[i]]=j;
              v[j]=1;
              return 1;
             }
         if(!v[a[i]])
           u[s[i]]=a[i],v[a[i]]=1;
         else
           return 0;
        }
    return 1;
}
inline bool chkb(int i)
{
    int j;
    for(j='a';j<='z';j++)
      u[j]=x[j],v[j]=y[j];
    u[s[i]]=b[i];
    v[b[i]]=1;
    for(i++;i<n;i++)
      if(u[s[i]])
        if(u[s[i]]>b[i])
          return 0;
        else if(u[s[i]]<b[i])
          return 1;
        else
          {}
      else
        {
         for(j='a';j<b[i];j++)
           if(!v[j])
             {
              u[s[i]]=j;
              v[j]=1;
              return 1;
             }
         if(!v[b[i]])
           u[s[i]]=b[i],v[b[i]]=1;
         else
           return 0;
        }
    return 1;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j;
    scanf("%d",&t);
    while(t--)
      {
       scanf("%d%s%s%s",&m,&s,&a,&b);
       m+='a'-1;
       n=strlen(s);
       for(i='a';i<='z';i++)
         x[i]=y[i]=0;
       p=0;
       for(i=0;i<n;i++)
         if(x[s[i]])
           if(x[s[i]]<a[i] || x[s[i]]>b[i])
             break;
           else if(x[s[i]]>a[i] && x[s[i]]<b[i])
             {
              p=1;
              break;
             }
           else if(x[s[i]]<b[i])
             {
             if(chka(i))
                {
                 for(j='a';j<='z';j++)
                   x[j]=u[j],y[j]=v[j];
                 p=1;
                }
                 break;
             }
           else if(x[s[i]]>a[i])
             {
             if(chkb(i))
                {
                 for(j='a';j<='z';j++)
                   x[j]=u[j],y[j]=v[j];
                 p=1;
                }
                 break;
             }
           else
             {}
         else
           if(a[i]==b[i])
             if(!y[a[i]])
               x[s[i]]=a[i],y[a[i]]=1;
             else
               break;
           else
             {
              for(j=a[i]+1;j<b[i];j++)
                if(!y[j])
                  {
                   x[s[i]]=j;
                   y[j]=1;
                   p=1;
                   break;
                  }
              if(j<b[i])
                break;
              if(!y[a[i]] && chka(i))
                {
                 for(j='a';j<='z';j++)
                   x[j]=u[j],y[j]=v[j];
                 p=1;
                 break;
                }
              if(!y[b[i]] && chkb(i))
                {
                 for(j='a';j<='z';j++)
                   x[j]=u[j],y[j]=v[j];
                 p=1;
                 break;
                }
              break;
             }
       if(i<n && !p)
         printf("NO\n");
       else
         {
          printf("YES\n");
          for(i='a',j='a';i<=m;i++)
            if(!x[i])
              {
               while(y[j])
                 j++;
               x[i]=j;
               y[j]=1;
              }
          for(i='a';i<=m;i++)
            printf("%c",x[i]);
          printf("\n");
         }
      }
    return 0;
}