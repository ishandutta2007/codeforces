import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class I {

	static final int MOD = 998244353;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static List<Item> pair(Item a, Item b) {
		List<Item> res = new ArrayList<>();
		res.add(a);
		res.add(b);
		return res;
	}

	static abstract class Item {

		boolean haveIn, haveOut;
		abstract void processPresence(List<Integer> elements);
		abstract Item process(int bound);
		abstract int count();
	}

	static class Person extends Item {
		final int index;

		Person(int index) {
			this.index = index;
		}

		void processPresence(List<Integer> elements) {
			boolean have = false;
			for (int i: elements) {
				if (i == index) {
					have = true;
					break;
				}
			}
			haveIn = have;
			haveOut = !have;
		}

		Item process(int bound) {
			return this;
		}

		int count() {
			return 1;
		}

		public String toString() {
			return Integer.toString(index);
		}
	}

	static abstract class MultiItem extends Item {
		final List<Item> contents;

		MultiItem(List<Item> contents) {
			this.contents = contents;
		}

		void processPresence(List<Integer> elements) {
			haveIn = haveOut = false;
			for (Item i: contents) {
				i.processPresence(elements);
				haveIn |= i.haveIn;
				haveOut |= i.haveOut;
			}
		}
	}

	static class Group extends MultiItem {

		Group(List<Item> contents) {
			super(contents);
		}

		static Item make(List<Item> items) {
			return items.size() == 1 ? items.get(0) : new Group(items);
		}

		Item process(int bound) {
			List<Item> full = new ArrayList<>(), partial = new ArrayList<>(), none = new ArrayList<>();
			for (Item i: contents) {
				if (i.haveIn) {
					if (i.haveOut) {
						partial.add(i);
					} else {
						full.add(i);
					}
				} else {
					none.add(i);
				}
			}
			switch (partial.size()) {
			case 0:
			{
				if (full.isEmpty() || none.isEmpty()) {
					return this;
				}
				Item fullItem = Group.make(full);
				if (bound == 0) {
					none.add(fullItem);
					return new Group(none);
				} else {
					Item noneItem = Group.make(none);
					return new Sequence(bound > 0 ? pair(fullItem, noneItem) : pair(noneItem, fullItem));
				}
			}
			case 1:
			{
				Item p = partial.get(0);
				if (bound == 0) {
					if (full.isEmpty()) {
						p = p.process(0);
						if (p == null) {
							return null;
						}
						none.add(p);
						return new Group(none);
					} else {
						p = p.process(1);
						if (p == null) {
							return null;
						}
						List<Item> pi = new ArrayList<>(((Sequence) p).contents);
						pi.add(0, Group.make(full));
						none.add(new Sequence(pi));
						return Group.make(none);
					}
				} else {
					p = p.process(bound);
					if (p == null) {
						return null;
					}
					List<Item> res = new ArrayList<>();
					if (!full.isEmpty()) {
						res.add(Group.make(full));
					}
					List<Item> els = ((Sequence) p).contents;
					if (bound > 0) {
						res.addAll(els);
					} else {
						res.addAll(0, els);
					}
					if (!none.isEmpty()) {
						if (bound > 0) {
							res.add(Group.make(none));
						} else {
							res.add(0, Group.make(none));
						}
					}
					return new Sequence(res);
				}
			}
			case 2:
			{
				if (bound != 0) {
					return null;
				}
				Item p1 = partial.get(0).process(-1), p2 = partial.get(1).process(1);
				if (p1 == null || p2 == null) {
					return null;
				}
				List<Item> sres = new ArrayList<>();
				sres.addAll(((Sequence) p1).contents);
				if (!full.isEmpty()) {
					sres.add(Group.make(full));
				}
				sres.addAll(((Sequence) p2).contents);
				none.add(new Sequence(sres));
				return Group.make(none);
			}
			default:
				return null;
			}
		}

		int count() {
			int res = 1;
			for (int i = 0; i < contents.size(); i++) {
				res = mul(mul(res, i + 1), contents.get(i).count());
			}
			return res;
		}

		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append('{');
			for (int i = 0; i < contents.size(); i++) {
				if (i != 0) {
					sb.append(", ");
				}
				sb.append(contents.get(i).toString());
			}
			sb.append('}');
			return sb.toString();
		}
	}

	static class Sequence extends MultiItem {

		Sequence(List<Item> contents) {
			super(contents);
		}

		Item process(int bound) {
			List<Item> els = new ArrayList<>(contents);
			int n = els.size();
			int p1 = 0;
			while (p1 < n && !els.get(p1).haveIn) {
				++p1;
			}
			int p2 = p1;
			while (p2 < n && els.get(p2).haveIn) {
				++p2;
			}
			for (int i = 0; i < n; i++) {
				Item ii = els.get(i);
				if (ii.haveIn != (i >= p1 && i < p2)) {
					return null;
				}
				if (i > p1 && i < p2 - 1 && ii.haveOut) {
					return null;
				}
			}
			if (!els.get(p1).haveOut && !els.get(p2 - 1).haveOut && (p1 == 0 || bound <= 0) && (p2 == n || bound >= 0)) {
				return this;
			}
			if (p2 == p1 + 1) {
				if (bound == 0) {
					Item ni = els.get(p1).process(0);
					if (ni == null) {
						return null;
					}
					els.set(p1, ni);
					return new Sequence(els);
				} else if (p1 != 0 && p1 != n - 1) {
					return null;
				} else {
					if ((p1 == 0) != (bound > 0)) {
						Collections.reverse(els);
						p1 = n - p1 - 1;
					}
					if (els.get(p1).haveOut) {
						Item ni = els.get(p1).process(bound);
						if (ni == null) {
							return null;
						}
						els.remove(p1);
						els.addAll(p1, ((Sequence) ni).contents);
					}
					return new Sequence(els);
				}
			}
			if (bound != 0) {
				boolean bad1 = p1 > 0 || els.get(p1).haveOut;
				boolean bad2 = p2 < n || els.get(p2 - 1).haveOut;
				if (bad1 && bad2) {
					return null;
				}
				if ((bound > 0 && bad1) || (bound < 0 && bad2)) {
					Collections.reverse(els);
					int t = p1;
					p1 = n - p2;
					p2 = n - t;
				}
			}
			if (els.get(p1).haveOut) {
				Item ni = els.get(p1).process(-1);
				if (ni == null) {
					return null;
				}
				els.remove(p1);
				els.addAll(p1, ((Sequence) ni).contents);
				p2 += ((Sequence) ni).contents.size() - 1;
			}
			if (els.get(p2 - 1).haveOut) {
				Item ni = els.get(p2 - 1).process(1);
				if (ni == null) {
					return null;
				}
				els.remove(p2 - 1);
				els.addAll(p2 - 1, ((Sequence) ni).contents);
			}
			return new Sequence(els);
		}

		int count() {
			int res = 2;
			for (int i = 0; i < contents.size(); i++) {
				res = mul(res, contents.get(i).count());
			}
			return res;
		}

		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append('[');
			for (int i = 0; i < contents.size(); i++) {
				if (i != 0) {
					sb.append(", ");
				}
				sb.append(contents.get(i).toString());
			}
			sb.append(']');
			return sb.toString();
		}
	}

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		List<Item> preRoot = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			preRoot.add(new Person(i));
		}
		Item root = Group.make(preRoot);
		for (int i = 0; i < m; i++) {
			List<Integer> cur = new ArrayList<>();
			int q = scanInt();
			for (int j = 0; j < q; j++) {
				cur.add(scanInt() - 1);
			}
			root.processPresence(cur);
			root = root.process(0);
			if (root == null) {
				out.print(0);
				return;
			}
		}
		out.print(root.count());
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}