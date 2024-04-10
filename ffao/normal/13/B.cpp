    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    struct node
    {
        int x,y,j,k;
    }a[10];
    int t,x,y,m,n,p,q,x1,yy,x2,y2,c1,c2,flag;
    int check_oneline(int a,int b,int c,int d,int e,int f)
    {
        if((ll)(f-b)*(c-a)==(ll)(d-b)*(e-a))
            return 1;
        return 0;
    }
    int check_angle(int x,int y,int a,int b,int p,int q)
    {
        if((ll)(a-x)*(p-x)+(ll)(b-y)*(q-y)<0)
            return 0;
        return 1;
    }
    int check_subseg(int x,int y,int m,int n,int a,int b)
    {
        if(x!=a)
        {
            if(a>x)
            {
                if((a-x)*5<(m-x)) 
                    return 0;
                if((a-x)*5>(m-x)*4) 
                    return 0;
                return 1;
            }
            else
            {
                if((x-a)*5<(x-m)) 
                    return 0;
                if((x-a)*5>(x-m)*4)
                    return 0;
                return 1;
            }
        }
        else
        {
            if(b>y)
            {
                if((b-y)*5<(n-y))
                    return 0;
                if((b-y)*5>(n-y)*4)
                    return 0;
                return 1;
            }
            else
            {
                if((y-b)*5<(y-n))
                    return 0;
                if((y-b)*5>(y-n)*4)
                    return 0;
                return 1;
            }
        }
    }
    int main()
    {
        scanf("%d",&t);
        while(t--) 
        {
            for(int i=1;i<=3;i++)
                scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].j,&a[i].k);
            for(int i=1;i<=2;i++) 
                for(int j=i+1;j<=3;j++)
                {
                    if(a[i].x==a[j].x&&a[i].y==a[j].y)
                    {
                        x=a[i].x,y=a[i].y;
                        m=a[i].j,n=a[i].k;
                        p=a[j].j,q=a[j].k;
                        c1=i,c2=j;
                    }
                    else if(a[i].x==a[j].j&&a[i].y==a[j].k)
                    {
                        x=a[i].x,y=a[i].y;
                        m=a[i].j,n=a[i].k;
                        p=a[j].x,q=a[j].y;
                        c1=i,c2=j;
                    }
                    else if(a[i].j==a[j].j&&a[i].k==a[j].k)
                    {
                        x=a[i].j,y=a[i].k;
                        m=a[i].x,n=a[i].y;
                        p=a[j].x,q=a[j].y;
                        c1=i,c2=j;
                    }
                    else if(a[i].j==a[j].x&&a[i].k==a[j].y)
                    {
                        x=a[i].j,y=a[i].k;
                        m=a[i].x,n=a[i].y;
                        p=a[j].j,q=a[j].k;
                        c1=i,c2=j;
                    }
                }
            for(int i=1;i<=3;i++)
                if(i!=c1&&i!=c2)
                {
                    x1=a[i].x,yy=a[i].y,x2=a[i].j,y2=a[i].k;
                    break;
                }
            flag=1; 
            if(check_angle(x,y,m,n,p,q)==0)
                flag=0;
            if(flag)
            {
                if(check_oneline(x,y,m,n,x1,yy)&&check_oneline(x,y,p,q,x2,y2))
                {
                    if(check_subseg(x,y,m,n,x1,yy)==0)
                        flag=0;
                    if(check_subseg(x,y,p,q,x2,y2)==0)
                        flag=0;
                }
                else if(check_oneline(x,y,p,q,x1,yy)&&check_oneline(x,y,m,n,x2,y2))
                {
                    if(check_subseg(x,y,m,n,x2,y2)==0)
                        flag=0;
                    if(check_subseg(x,y,p,q,x1,yy)==0)
                        flag=0;
                }
                else 
                    flag=0;
            }
            printf(flag?"YES\n":"NO\n");
        }
        return 0;
    }