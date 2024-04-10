using System;
using System.Linq;

public static class Program
{
	
    public static void Main()
    {
		int [] b=new int[200005];
		b[0]=0;
        var nn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var n = nn[0];
		var top=0;
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        for(int i=0;i<n;i++)
		{
		    
			var now=a[i];
			//Console.WriteLine(now);
			while(b[top]==now&&top>0)
			{
				now++;top--;
			}
			top++;
			b[top]=now;
			//Console.WriteLine(top);
		}
        Console.WriteLine(top);
        for(int i=1;i<=top;i++)
        {
            Console.Write(b[i]);
            Console.Write(" ");
        }
    }
}