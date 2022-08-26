import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class MacrosCheck implements Runnable {
	private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private PrintWriter out = new PrintWriter(System.out);
	private int n;
	private Map<String, String> m = new HashMap<String, String>();
	private String s;
	private boolean ans;
	private HashSet<String> g1, g2, b1, b2, b3, g3;

	public static void main(String[] args) {
		new Thread(new MacrosCheck()).start();
	}

	private void read() {
		try {
			n = Integer.parseInt(in.readLine().trim());
			for (int i = 0; i < n; i++) {
				String buf = in.readLine().trim();
				buf = buf.replaceFirst("#", "");
				buf = buf.replaceFirst("define", "");
				buf = buf.trim();
				Scanner s = new Scanner(buf);
				String id = s.next();
				buf = buf.replaceFirst(id, "");
				m.put(id, buf.trim());
			}
			s = in.readLine().trim();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	private void solve() {
		g1 = new HashSet<String>();
		g2 = new HashSet<String>();
		b1 = new HashSet<String>();
		b2 = new HashSet<String>();
		b3 = new HashSet<String>();
		g3 = new HashSet<String>();
		ans = go(s, 0);
	}

	private boolean go(String s, int pp) {
		if (g1.contains(s) && pp == 0 || g2.contains(s) && pp <= 1 || g3.contains(s))
			return true;
		if (b1.contains(s) || b2.contains(s) && pp >= 1 || b3.contains(s) && pp == 2)
			return false;
		int b = 0;
		boolean result = true;
		List<Integer> p = new ArrayList<Integer>();
		boolean w = false;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(')
				b++;
			else if (s.charAt(i) == ')')
				b--;
			else if (b == 0) {
				if (s.charAt(i) == '+') {
					if (pp != 0)
						result = false;
					p.add(i);
				}
				if (s.charAt(i) == '-') {
					if (pp != 0)
						result = false;
					p.add(i);
				}
			}
		}
		if (result && !p.isEmpty()) {
			w = true;
			p.add(s.length());
			for (int i = 0; i < p.size(); i++) {
				int l = i == 0 ? 0 : p.get(i - 1) + 1;
				if (l == 0 || s.charAt(l - 1) == '+')
					result = result && go(s.substring(l, p.get(i)).trim(), 0);
				else
					result = result && go(s.substring(l, p.get(i)).trim(), 1);
			}
		}
		if (p.isEmpty()) {
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '(')
					b++;
				else if (s.charAt(i) == ')')
					b--;
				else if (b == 0) {
					if (s.charAt(i) == '*') {
						if (pp == 2)
							result = false;
						p.add(i);
					}
					if (s.charAt(i) == '/') {
						if (pp == 2)
							result = false;
						p.add(i);
					}
				}
			}
		}
		if (!w && result && !p.isEmpty()) {
			p.add(s.length());
			for (int i = 0; i < p.size(); i++) {
				int l = i == 0 ? 0 : p.get(i - 1) + 1;
				if (l == 0 || s.charAt(l - 1) == '*')
					result = result && go(s.substring(l, p.get(i)).trim(), 1);
				else
					result = result && go(s.substring(l, p.get(i)).trim(), 2);
			}
		}
		if (p.isEmpty()) {
			if (s.startsWith("("))
				result = go(s.substring(1, s.length() - 1).trim(), 0);
			else
				result = !m.containsKey(s) || go(m.get(s), pp);
		}
		if (result) {
			if (pp == 0)
				g1.add(s);
			else if (pp == 1)
				g2.add(s);
			else if (pp == 2)
				g3.add(s);
		} else {
			if (pp == 0)
				b1.add(s);
			else if (pp == 1)
				b2.add(s);
			else if (pp == 2)
				b3.add(s);
		}
		return result;
	}


	private void write() {
		if (ans)
			out.println("OK");
		else
			out.println("Suspicious");
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}
}