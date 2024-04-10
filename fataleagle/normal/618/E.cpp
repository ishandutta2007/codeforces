#include <bits/stdc++.h>

using namespace std;

struct matrix
{
    double data[3][3];
    matrix()
    {
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                data[i][j]=0.0;
    }
    matrix operator* (const matrix& other)
    {
        matrix ret;
        for(int i=0; i<3; i++)
            for(int k=0; k<3; k++)
                for(int j=0; j<3; j++)
                    ret.data[i][j]+=data[i][k]*other.data[k][j];
        return ret;
    }
} id;

matrix mat_trans(double x, double y)
{
    matrix m;
    m.data[0][0]=1.0, m.data[0][1]=0.0, m.data[0][2]=x;
    m.data[1][0]=0.0, m.data[1][1]=1.0, m.data[1][2]=y;
    m.data[2][0]=0.0, m.data[2][1]=0.0, m.data[2][2]=1.0;
    return m;
}

matrix mat_rot(double ang) // ccw
{
    matrix m;
    m.data[0][0]=cos(ang), m.data[0][1]=-sin(ang), m.data[0][2]=0.0;
    m.data[1][0]=sin(ang), m.data[1][1]=cos(ang), m.data[1][2]=0.0;
    m.data[2][0]=0.0, m.data[2][1]=0.0, m.data[2][2]=1.0;
    return m;
}

matrix seg[1<<20];

void build(int idx, int begin, int end)
{
    if(begin==end)
    {
        seg[idx].data[0][0]=begin-1;
        seg[idx].data[1][0]=0;
        seg[idx].data[2][0]=1.0;
    }
    else
    {
        int mid=(begin+end)/2;
        build(idx*2, begin, mid);
        build(idx*2+1, mid+1, end);
        seg[idx]=id;
    }
}

void down(int idx)
{
    seg[idx*2]=seg[idx]*seg[idx*2];
    seg[idx*2+1]=seg[idx]*seg[idx*2+1];
    seg[idx]=id;
}

void update(int idx, int begin, int end, int l, int r, matrix m)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
        seg[idx]=m*seg[idx];
    else
    {
        down(idx);
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, l, r, m);
        update(idx*2+1, mid+1, end, l, r, m);
    }
}

matrix query(int idx, int begin, int end, int x)
{
    if(x<begin || end<x)
        return id;
    if(begin==end)
        return seg[idx];
    down(idx);
    int mid=(begin+end)/2;
    return query(idx*2, begin, mid, x)*
           query(idx*2+1, mid+1, end, x);
}

const double PI=acos(-1.0);
int N, M;

int main()
{
    for(int i=0; i<3; i++)
        id.data[i][i]=1.0;
    scanf("%d%d", &N, &M);
    N++;
    build(1, 1, N);
    int a, b, op;
    for(int i=1; i<=M; i++)
    {
        scanf("%d%d%d", &op, &a, &b);
        if(op==1)
        {
            matrix r1=query(1, 1, N, a);
            matrix r2=query(1, 1, N, a+1);
            double dx=r2.data[0][0]-r1.data[0][0];
            double dy=r2.data[1][0]-r1.data[1][0];
            double ang=atan2(dy, dx);
            update(1, 1, N, a+1, N, mat_trans(b*cos(ang), b*sin(ang)));
        }
        else
        {
            matrix r=query(1, 1, N, a);
            double x=r.data[0][0];
            double y=r.data[1][0];
            b=360-b;
            double ang=PI*b/180.0;
            update(1, 1, N, a+1, N, mat_trans(x, y)*mat_rot(ang)*mat_trans(-x, -y));
        }
        matrix ans=query(1, 1, N, N);
        printf("%.6f %.6f\n", ans.data[0][0], ans.data[1][0]);
    }
    return 0;
}