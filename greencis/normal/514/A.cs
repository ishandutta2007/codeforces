using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;

class Program
{
    static void Main(string[] args)
    {
        //Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture; // Init

        string s = Console.ReadLine();
        for (int i = 0; i < s.Length; ++i)
        {
            if (s[i] == '9')
            {
                if (i == 0) Console.Write('9');
                else Console.Write('0');
            }
            else if (s[i] == '8') Console.Write('1');
            else if (s[i] == '7') Console.Write('2');
            else if (s[i] == '6') Console.Write('3');
            else if (s[i] == '5') Console.Write('4');
            else Console.Write(s[i]);
        }

        //Console.ReadLine(); // Pause
    }
}