using System;
class Program
{
    static void Main()
    {
        string c;
        int n = Convert.ToInt32(Console.ReadLine());
        c = Console.ReadLine();
        for (var i = 0; i < n; ++i)
        { 
            if(c[i]!='a'&&c[i]!='e'&&c[i]!='i'&&c[i]!='o'&&c[i]!='u'&&c[i]!='y')
            Console.Write(c[i]);
            else if(i==0||c[i]!=c[i-1])
            Console.Write(c[i]);
            else if((c[i]=='o'||c[i]=='e')&&(i==n-1||c[i]!=c[i+1])&&(i<2||c[i]!=c[i-2]))
            Console.Write(c[i]);
        }
        

    }

}